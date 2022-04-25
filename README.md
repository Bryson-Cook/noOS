# noOS

Welcome to noOS, as its name implies, noOS stands for no Operating System. 

## Our Story

Our team took a look at all of the competition including Windows, macOS, and various distributions of Linux. 
We realized that they lack a variety of productivity enhancing features. 
Sure, some applications have the ability to go fullscreen and you can disable notifications with a focus mode or do not disturb feature. 
What all of these operating systems lack is the ability to disable all of that.
With that in mind, we set out with a goal, to remove all distractions

## Technical info
This is a 32 bit x86 kernel, that currently uses GRUB as its bootloader using the multiboot standard.

It has a simple driver that allows it to communicate with x86's VGA buffer to display text.
Although this does work, the VGA text mode (as well as the BIOS) are no longer used in newer computer systems.

When booted it is in 32 bit protected mode with paging disabled.

### Installation
So far, this project has only been emulated. You may use a virtual machine to run this, my weapon of choice was qemu.

To run this in qemu:

`qemu-system-i386 -drive format=raw,file=noOS.iso`

![noOS](https://user-images.githubusercontent.com/97703215/164989700-cd526073-eb74-43c2-ae81-2156a11454cf.png)
