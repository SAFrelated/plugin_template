/*******************************************************************************
The content of this file includes portions of the AUDIOKINETIC Wwise Technology
released in source code form as part of the SDK installer package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use this file in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Apache License Usage

Alternatively, this file may be used under the Apache License, Version 2.0 (the
"Apache License"); you may not use this file except in compliance with the
Apache License. You may obtain a copy of the Apache License at
http://www.apache.org/licenses/LICENSE-2.0.

Unless required by applicable law or agreed to in writing, software distributed
under the Apache License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
OR CONDITIONS OF ANY KIND, either express or implied. See the Apache License for
the specific language governing permissions and limitations under the License.

  Copyright (c) 2020 Audiokinetic Inc.
*******************************************************************************/

#include "plugin_template.h"
#include "plugin_templatePlugin.h"
#include "../plugin_templateConfig.h"

#include <AK/Wwise/Utilities.h>
#include <AK/Tools/Common/AkAssert.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(plugin_templateApp, CWinApp)
END_MESSAGE_MAP()

plugin_templateApp::plugin_templateApp()
{
}

plugin_templateApp theApp;

BOOL plugin_templateApp::InitInstance()
{
    CWinApp::InitInstance();
    AK::Wwise::RegisterWwisePlugin();
    return TRUE;
}

AK::Wwise::IPluginBase* __stdcall AkCreatePlugin(unsigned short in_companyID, unsigned short in_pluginID)
{
    if (in_companyID == plugin_templateConfig::CompanyID && in_pluginID == plugin_templateConfig::PluginID)
        return new plugin_templatePlugin;

    return nullptr;
}

DEFINEDUMMYASSERTHOOK;
DEFINE_PLUGIN_REGISTER_HOOK;
