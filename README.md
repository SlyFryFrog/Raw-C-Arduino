# Raw-C Arduino Lib

## Introduction

This project is an implementation of utility libraries written in raw-C for an Arduino Uno R3. 

#### **Supported Features**

- Digital read/write for GPIO pins.

#### **Work-in-progress Features**

- Analog read/write for GPIO pins.
- UART over RX/TX.

## Setup

### Prerequisites

- `avrdude`
- `avrgcc`
- `Arduino Uno R3`

Before running make, it is necessary to modify the path of `PORT` in `Makefile` to point to your arduino's serial input.
In order to find this path, run ``

After this is set, simply run the following commands to build then flash.

```
make all
make flash
```

## Datasheets

The datasheets listed here were referenced during the development of the library.

- https://www.ti.com/lit/ug/sprugp1/sprugp1.pdf
- https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf