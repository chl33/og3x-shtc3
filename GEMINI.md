# og3x-shtc3 Development Mandates

This is an extension library for the `og3` framework. It must adhere to the core standards defined in the main `og3` repository.

## Coding Standards
- **Naming**: Follow `og3` conventions: `camelCase` methods, `snake_case` locals, `m_` prefix for private members.
- **Documentation**: All public/protected members in headers MUST use Doxygen-style comments.
- **Namespaces**: Use the `og3::` namespace. 

## Architecture & Integration
- **Module System**: Features must be implemented as `og3::Module` subclasses.
- **Base Classes**: Use `TempHumidity` base class for standardized climate sensing.

## Quality
- **CHANGELOG**: Maintain a `CHANGELOG.md` following the [Keep a Changelog](https://keepachangelog.com/) format.
- **Compatibility**: Ensure the library remains compatible with both ESP32 and ESP8266 platforms.
