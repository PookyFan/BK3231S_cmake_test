#This script performs final preparations of firmware image so that it could be flashed and used on the MCU

import sys

#CRC functions courtesy of mr_woggle

POLY = 0x8005
CRC_SEED = 0xFFFF
CHUNK_SIZE = 32
CONFIG_OFFSET = 0x40000
FLASH_SIZE = 0x80000

def crc16(data):
    crc = CRC_SEED
    for byte in data:
        crc ^= byte << 8
        for _ in range(8):
            if crc & 0x8000:
                crc = (crc << 1) ^ POLY
            else:
                crc <<= 1
    return crc & 0xFFFF

def add_padding(file, padding_size):
    padding = bytes([0xFF]*padding_size)
    file.write(padding)

if(len(sys.argv) < 4):
    print("prepare_image.py: need to specify input and output file names plus config file name")
    sys.exit(1)

input_filename = sys.argv[1]
output_filename =  sys.argv[2]
config_filename =  sys.argv[3]
output_file_size = 0
with open(input_filename, 'rb') as infile, open(output_filename, 'wb') as outfile:
    #Add CRC
    while True:
        chunk = infile.read(CHUNK_SIZE)
        if not chunk:
            break
        if len(chunk) < CHUNK_SIZE:
            chunk += b'\xFF' * (CHUNK_SIZE - len(chunk))
            chunk = chunk[:-1] + b'\xFF' # last byte also 0xFF?
        outfile.write(chunk)
        crc_val = crc16(chunk)
        crc_bytes = crc_val.to_bytes(length=2, byteorder='big')
        outfile.write(crc_bytes)  # Add two bytes (16-bit crc)
        output_file_size += len(chunk) + 2
    
    #Add padding before configuration
    if output_file_size > CONFIG_OFFSET: #todo: move configuration region to the end of the flash (requires changing C code in many places)
        print(f"prepare_image.py: output image too large ({output_file_size} bytes)")
        sys.exit(1)
    elif output_file_size < CONFIG_OFFSET:
        padding_size = CONFIG_OFFSET - output_file_size
        add_padding(outfile, padding_size)
        output_file_size += padding_size
    
    with open(config_filename, 'rb') as confile:
        conf = confile.read()
        outfile.write(conf)
        output_file_size += len(conf)
    
    #Add final padding
    add_padding(outfile, FLASH_SIZE - output_file_size)

print(f"prepare_image.py: done preparing image!")