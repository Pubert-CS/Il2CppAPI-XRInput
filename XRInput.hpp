#pragma once
#include <../Engine/Includes.hpp>
#include <string>

struct InputDevice {
    unsigned long m_DeviceId;
};

enum Controller {
    Left,
    Right
};

enum BoolFeature {
    PrimaryButton,
    PrimaryTouch,
    SecondaryButton,
    SecondaryTouch,
    GripButton,
    TriggerButton,
    MenuButton,
    Primary2DAxisClick,
    Primary2DAxisTouch,
    Secondary2DAxisClick,
    Secondary2DAxisTouch
};

vector<string> boolStrs { "PrimaryButton" , "PrimaryTouch", "SecondaryButton", "SecondaryTouch", "GripButton", "TriggerButton", "MenuButton", "Primary2DAxisClick", "Primary2DAxisTouch", "Secondary2DAxisClick", "Secondary2DAxisTouch" };

enum FloatFeature {
    Trigger,
    Grip
};

vector<string> floatStrs { "Trigger", "Grip" };

enum Vector2Feature {
    Primary2DAxis,
    Secondary2DAxis
};

vector<string> vectorStrs { "Primary2DAxis", "Secondary2DAxis" };

namespace XRInput {
    static bool GetBoolFeature(BoolFeature feature, Controller con);

    static float GetFloatFeature(FloatFeature feature, Controller con);

    static Vector2 GetVector2Feature(Vector2Feature feature, Controller con);

    static void SendHapticImpulse(Controller con, float amp, float dur);
};