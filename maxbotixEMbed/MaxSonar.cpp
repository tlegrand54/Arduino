/**
 * @file MaxSonar.cpp
 * @section LICENSE
 * Copyright (c) 2010 Mustafa Ozgur Kanli.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"),to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @section Description
 * Implementation of MaxSonar class.
 */

#include "mbed.h"
#include "MaxSonar.h"

MaxSonar::MaxSonar(enum MSType type, enum MSMode mode,
                   PinName pin1, PinName pin2) {
    
    // Set some defaults common to all devices.
    this->units = MS_CM;
    this->voltage = 3.3;
    this->ain = NULL;
    this->rx_req = NULL;

    // Save settings.
    this->type = type;
    this->mode = mode;

    // Device specific settings.
    switch(this->type) {
        case MS_LV:
            this->analog_scale = 512;
            break;
        
        // @todo Add functionality.    
        case MS_WR:
        case MS_WRC:
        case MS_XL:
        case MS_XL_AE:
        default:
            error("MaxSonar: Currently unsupported.\n");
            break;
    }

    // Mode specific settings.
    switch(this->mode) {
        case MS_ANALOG:
            if (pin1 != NC)
            {
                rx_req = new DigitalOut(pin1);
                rx_req->write(0);       // Default low to stop it ranging.
            }
            ain = new AnalogIn(pin2);
            this->analog_resolution = this->voltage / this->analog_scale;
            break;

        // @todo Add functionality.            
        case MS_SERIAL:
        case MS_PWM:
        default:
            error("MaxSonar: Currently unsupported.\n");
            break;
    }
}

MaxSonar::~MaxSonar(void) {
    delete ain;
}

void MaxSonar::setUnits(enum MSUnits units) {
    this->units = units;
}

void MaxSonar::setVoltage(float voltage) {
    this->voltage = voltage;
    this->analog_resolution = this->voltage / this->analog_scale;
}

void MaxSonar::triggerRead(void) {

    if (rx_req != NULL)
    {
        // Bring rx line high for 20us to perform a read. The read will
        // be available 49ms after request.
        rx_req->write(1);
        wait_us(20);
        rx_req->write(0);
    }
}

float MaxSonar::read(void) {
    
    float range;

    // Make the reading.
    switch(this->mode) {
        case MS_ANALOG:
            //! Range value is computed in inches by default.
            range = (this->ain->read() * this->voltage) / this->analog_resolution;
            break;

        // @todo Add functionality.            
        case MS_SERIAL:
        case MS_PWM:
        default:
            error("MaxSonar: Currently unsupported.\n");
            break;
    }
    
    // Perform conversion.
    switch(this->units) {
        case MS_CM:
            range *= 2.54;
            break;
        
        case MS_INCH:
            break;
            
        default:
            error("MaxSonar: Currently unsupported.\n");
            break;
    }
    
    return range;
}

