#include "pch.h"

#include <AHooks.h>
#include <AImGUI.h>
#include <HookHelpers.h>
#include <ModLoader.h>

#include <BYardSDK/ACamera.h>
#include <BYardSDK/AGUI2.h>
#include <BYardSDK/AGUI2FontManager.h>
#include <BYardSDK/AGameStateController.h>
#include <BYardSDK/APlayerManager.h>
#include <BYardSDK/ASteer.h>
#include <BYardSDK/ATerrainInterface.h>
#include <BYardSDK/THookedRenderD3DInterface.h>

#include <File/TFile.h>
#include <Toshi/THPTimer.h>
#include <Toshi/TScheduler.h>
#include <ToshiTools/T2CommandLine.h>

#include "Addresses.h"

TOSHI_NAMESPACE_USING

class ACheatMenu : public AModInstance {
  public:
    TBOOL OnLoad() OVERRIDE {
        initAddresses();
        return TTRUE;
    }

    void OnUnload() OVERRIDE {
        deleteAddresses();
    }

    void OnRenderInterfaceReady(Toshi::TRenderD3DInterface *a_pRenderInterface) OVERRIDE {
        TRenderInterface::SetSingletonExplicit(THookedRenderD3DInterface::GetSingleton());
    }

    void OnImGuiRender(AImGUI *a_pImGui) OVERRIDE {
        if (ImGui::CollapsingHeader("Movement")) {
            for (FloatAddress &cheat : *movementCheats) {
                if (ImGui::InputFloat(cheat.label, &cheat.currentValue)) {
                    cheat.write(cheat.currentValue);
                }
            }
            if (ImGui::Button("Revert All")) {
                for (FloatAddress &cheat : *movementCheats) {
                    cheat.revert();
                }
            }
        }
    }

    TBOOL HasSettingsUI() OVERRIDE {
        return TTRUE;
    }

    virtual TBOOL IsOverlayVisible() OVERRIDE {
        return TTRUE;
    }
};

extern "C" {
    MODLOADER_EXPORT AModInstance *CreateModInstance(const T2CommandLine *a_pCommandLine) {
        TMemory::Initialise(1 * 1024 * 1024, 0); // TODO: Specify max memory size to allocate for the mod

        TUtil::TOSHIParams toshiParams;
        toshiParams.szCommandLine = "";
        toshiParams.szLogFileName = "cheat-menu";
        toshiParams.szLogAppName = "CheatMenu";

        TUtil::ToshiCreate(toshiParams);

        return new ACheatMenu();
    }

    MODLOADER_EXPORT const TCHAR *GetModAutoUpdateURL() {
        return "https://github.com/Break-Ben/BarnyardMods/releases/download/CheatMenu-latest/update.json";
    }

    MODLOADER_EXPORT const TCHAR *GetModName() {
        return "Cheat Menu";
    }

    MODLOADER_EXPORT TUINT32 GetModVersion() {
        return TVERSION(0, 1);
    }
}