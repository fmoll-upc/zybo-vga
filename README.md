# zybo-vga

VHDL code for building a VGA driver for the Zybo

## Brief file description

### VGA_SYNC.vhd
VGA signal driver for 3-bit color inputs and 25 MHz clock. It generates VGA signals with correct timing as well as pixel_row and pixel_column, 10 bits each, to point to the current pixel. Using other IPs or logic, the appropriate color of each pixel is selected based on the value of pixel_row and pixel_colummn.

### screenObject.vhd
This is an example to represent one object of 16x16 pixel size, in a position on the screen given by inputs cx and cy. The position uses the 6 MSB of pixel_row and pixel_column, offering a positioning grid of 64x64 possible positions.

### CLK_DIV.vhd
This block can be used in case an external clock signal needs to be divided to obtain the required 25 MHz. If the Zynq IP is used, it is better to generate directly the required 25 MHz and not use this IP.


## Instructions for use

1. Download VHDL and XDC files for use in Vivado.
2. Build IP for each of the desired components.
3. Use new IPs in your schematic.
4. Include XDC file in Constraints
