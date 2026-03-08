// Copyright (c) 2026 Chris Lee and contributors.
// Licensed under the MIT license. See LICENSE file in the project root for details.

#pragma once

#include <Adafruit_I2CDevice.h>
#include <Adafruit_SHTC3.h>
#include <og3/temp_humidity.h>

#include <functional>

namespace og3 {

/**
 * @brief Module for reading temperature and humidity from an SHTC3 sensor.
 *
 * This class wraps the Adafruit SHTC3 library and integrates it with the
 * og3 framework's TempHumidity base class for standardized climate reporting
 * and Home Assistant discovery.
 */
class Shtc3 : public TempHumidity {
 public:
  /**
   * @brief Constructs an Shtc3 module.
   * @param temp_name Name for the temperature variable.
   * @param humidity_name Name for the humidity variable.
   * @param module_system_ The ModuleSystem to register with.
   * @param description Human-readable description of the sensor.
   * @param vg The VariableGroup to add state variables to.
   * @param publish true to publish values via MQTT.
   * @param ha_discovery true to enable Home Assistant discovery.
   * @param two_wire Optional pointer to a custom TwoWire (I2C) instance.
   */
  Shtc3(const char* temp_name, const char* humidity_name, ModuleSystem* module_system_,
        const char* description, VariableGroup& vg, bool publish = true, bool ha_discovery = true,
        TwoWire* two_wire = nullptr);

  /**
   * @brief Reads the latest values from the hardware sensor.
   * @return true if the read was successful.
   */
  bool read();

 private:
  Adafruit_SHTC3 m_shtc3;
  TwoWire* m_two_wire = nullptr;
};

}  // namespace og3
