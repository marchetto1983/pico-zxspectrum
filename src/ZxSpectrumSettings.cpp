#include "ZxSpectrumSettings.h"

ZxSpectrumSettings::ZxSpectrumSettings()
{
}

ZxSpectrumSettings::~ZxSpectrumSettings()
{
}

void ZxSpectrumSettings::sanitise(ZxSpectrumSettingValues *values) {

    // Volume
    if (values->volume > 0x100) values->volume = 0x100;

    // Joystick
    switch(values->joystickMode) {
      case ZxSpectrumJoystickModeKempston:
      case ZxSpectrumJoystickModeSinclair:
        break;
      default: 
        values->joystickMode = ZxSpectrumJoystickModeKempston;
        break;
    }
}

bool ZxSpectrumSettings::onSave(ZxSpectrumSettingValues *values)
{
    return false;
}

bool ZxSpectrumSettings::onLoad(ZxSpectrumSettingValues *values)
{
    return false;
}

bool ZxSpectrumSettings::save(ZxSpectrumSettingValues *values)
{
    sanitise(values);
    return onSave(values);
}

bool ZxSpectrumSettings::load(ZxSpectrumSettingValues *values)
{
    defaults(values);
    bool r = onLoad(values);
    sanitise(values);
    return r;
}

void ZxSpectrumSettings::defaults(ZxSpectrumSettingValues *values) {
  values->volume = 0x100;
  values->joystickMode = ZxSpectrumJoystickModeKempston;
}
