#include <iostream>
#include <mmdeviceapi.h>
#include <endpointvolume.h>

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR commandLine, int nCmdShow) {
    int exitCode = 0;
    char *action = commandLine;
    IMMDeviceEnumerator *pEnumerator = nullptr;
    IMMDevice *pDevice = nullptr;
    IAudioEndpointVolume *audioEndpointVolume = nullptr;

    CoInitialize(nullptr);
    CoCreateInstance(__uuidof(MMDeviceEnumerator), nullptr, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator),
                     (void **) &pEnumerator);
    pEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &pDevice);
    pDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, nullptr, (void **) &audioEndpointVolume);

    float volume;
    if (_stricmp(action, "mute") == 0) {
        BOOL isMuted;
        audioEndpointVolume->GetMute(&isMuted);
        audioEndpointVolume->SetMute(!isMuted, nullptr);
    } else if (_stricmp(action, "up") == 0) {
        audioEndpointVolume->GetMasterVolumeLevelScalar(&volume);
        audioEndpointVolume->SetMasterVolumeLevelScalar(volume + 0.01f, nullptr);
    } else if (_stricmp(action, "down") == 0) {
        audioEndpointVolume->GetMasterVolumeLevelScalar(&volume);
        audioEndpointVolume->SetMasterVolumeLevelScalar(volume - 0.01f, nullptr);
    } else {
        std::cerr << "Usage: volumectl.exe up|down|mute" << std::endl;
        exitCode = 1;
    }

    pEnumerator->Release();
    pDevice->Release();
    audioEndpointVolume->Release();
    return exitCode;
}