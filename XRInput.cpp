#pragma once
#include <XRInput.hpp>
#include <string>
#include "../Engine/Includes.hpp"

bool XRInput::GetBoolFeature(BoolFeature feature, Controller con) {
    auto GetDeviceAtXRNode = Il2Cpp::GetMethod<InputDevice(*)(int)>("UnityEngine.XRModule.dll", "UnityEngine.XR", "InputDevices", "GetDeviceAtXRNode", 1);
    auto TryGetFeatureValue_bool = Il2Cpp::GetMethod<bool(*)(unsigned long, Il2CppString*, bool*)>("UnityEngine.XRModule.dll", "UnityEngine.XR", "InputDevices", "TryGetFeatureValue_bool", 3);
    unsigned long id = (con == Controller::Left) ? GetDeviceAtXRNode(4).m_DeviceId : GetDeviceAtXRNode(5).m_DeviceId;
    bool output;
    TryGetFeatureValue_bool(id, Il2Cpp::CreateString(boolStrs[feature].c_str()), &output);
    return output;
}

float XRInput::GetFloatFeature(FloatFeature feature, Controller con) {
    auto GetDeviceAtXRNode = Il2Cpp::GetMethod<InputDevice(*)(int)>("UnityEngine.XRModule.dll", "UnityEngine.XR", "InputDevices", "GetDeviceAtXRNode", 1);
    auto TryGetFeatureValue_float = Il2Cpp::GetMethod<bool(*)(unsigned long, Il2CppString*, float*)>("UnityEngine.XRModule.dll", "UnityEngine.XR", "InputDevices", "TryGetFeatureValue_float", 3);
    unsigned long id = (con == Controller::Left) ? GetDeviceAtXRNode(4).m_DeviceId : GetDeviceAtXRNode(5).m_DeviceId;
    float output;
    TryGetFeatureValue_float(id, Il2Cpp::CreateString(floatStrs[feature].c_str()), &output);
    return output;
}

Vector2 XRInput::GetVector2Feature(Vector2Feature feature, Controller con) {
    auto GetDeviceAtXRNode = Il2Cpp::GetMethod<InputDevice(*)(int)>("UnityEngine.XRModule.dll", "UnityEngine.XR", "InputDevices", "GetDeviceAtXRNode", 1);
    auto TryGetFeatureValue_Vector2f = Il2Cpp::GetMethod<bool(*)(unsigned long, Il2CppString*, Vector2*)>("UnityEngine.XRModule.dll", "UnityEngine.XR", "InputDevices", "TryGetFeatureValue_Vector2f", 3);
    unsigned long id = (con == Controller::Left) ? GetDeviceAtXRNode(4).m_DeviceId : GetDeviceAtXRNode(5).m_DeviceId;
    Vector2 output;
    TryGetFeatureValue_Vector2f(id, Il2Cpp::CreateString(vectorStrs[feature].c_str()), &output);
    return output;
}

void XRInput::SendHapticImpulse(Controller con, float amp, float dur) {
    auto GetDeviceAtXRNode = Il2Cpp::GetMethod<InputDevice(*)(int)>("UnityEngine.XRModule.dll", "UnityEngine.XR", "InputDevices", "GetDeviceAtXRNode", 1);
    auto SendHapticImpulse = Il2Cpp::GetMethod<bool(*)(unsigned long, uint, float, float)>("UnityEngine.XRModule.dll", "UnityEngine.XR", "InputDevices", "SendHapticImpulse", 4);
    unsigned long id = (con == Controller::Left) ? GetDeviceAtXRNode(4).m_DeviceId : GetDeviceAtXRNode(5).m_DeviceId;
    SendHapticImpulse(id, 0u, amp, dur);
}
