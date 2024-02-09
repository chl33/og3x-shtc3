// Copyright (c) 2024 Chris Lee and contibuters.
// Licensed under the MIT license. See LICENSE file in the project root for details.

#pragma once

#include <Adafruit_SHTC3.h>
#include <og3/temp_humidity.h>

#include <functional>

namespace og3 {

class Shtc3 : public TempHumidity {
 public:
  Shtc3(const char* temp_name, const char* humidity_name, ModuleSystem* module_system_,
        const char* description, VariableGroup* vg, bool publish = true, bool ha_discovery = true,
        TwoWire* two_wire = nullptr)
      : TempHumidity(temp_name, humidity_name, module_system_, description, vg, publish,
                     ha_discovery),
        m_two_wire(two_wire) {
    add_start_fn([this]() {
      // Use the default i2c-twowire if not explicitly specified.
      m_ok = m_shtc3.begin(m_two_wire ? m_two_wire : &Wire);
    });
  }

  bool read() {
    sensors_event_t humidity, temp;
    if (!m_ok || !m_shtc3.getEvent(&humidity, &temp)) {
      return readingFailed();
    }
    m_humidity = humidity.relative_humidity;
    m_temperature = temp.temperature;
    return true;
  }

 private:
  Adafruit_SHTC3 m_shtc3;
  TwoWire* m_two_wire = nullptr;
};

}  // namespace og3
