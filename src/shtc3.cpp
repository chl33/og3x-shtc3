// Copyright (c) 2026 Chris Lee and contibuters.
// Licensed under the MIT license. See LICENSE file in the project root for details.

#include "og3/shtc3.h"

namespace og3 {

Shtc3::Shtc3(const char* temp_name, const char* humidity_name, ModuleSystem* module_system_,
             const char* description, VariableGroup& vg, bool publish, bool ha_discovery,
             TwoWire* two_wire)
    : TempHumidity(temp_name, humidity_name, module_system_, description, vg, publish,
                   ha_discovery),
      m_two_wire(two_wire) {
  add_start_fn([this]() {
    // Use the default i2c-twowire if not explicitly specified.
    m_ok = m_shtc3.begin(m_two_wire ? m_two_wire : &Wire);
  });
}

bool Shtc3::read() {
  sensors_event_t humidity, temp;
  if (!m_ok || !m_shtc3.getEvent(&humidity, &temp)) {
    return readingFailed();
  }
  m_humidity = humidity.relative_humidity;
  m_temperature = temp.temperature;
  return true;
}

}  // namespace og3
