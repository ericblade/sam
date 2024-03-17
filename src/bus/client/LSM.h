// Copyright (c) 2012-2020 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#ifndef BUS_CLIENT_LSM_H_
#define BUS_CLIENT_LSM_H_

#include <luna-service2/lunaservice.hpp>
#include <boost/signals2.hpp>
#include <pbnjson.hpp>

#include "AbsLunaClient.h"
#include "interface/ISingleton.h"
#include "util/Logger.h"

using namespace LS;
using namespace pbnjson;

class LSM : public ISingleton<LSM>,
            public AbsLunaClient {
friend class ISingleton<LSM>;
public:
    virtual ~LSM();

    boost::signals2::signal<void(const JValue&)> EventRecentsAppListChanged;

    void getForegroundInfoById(const string& appId, JValue& info)
    {
        if (!m_foregroundInfo.isArray() || m_foregroundInfo.arraySize() < 1)
            return;

        for (auto item : m_foregroundInfo.items()) {
            if (!item.hasKey("appId") || !item["appId"].isString())
                continue;

            if (item["appId"].asString() == appId) {
                info = item.duplicate();
                return;
            }
        }
    }

    const string& getFullWindowAppId()
    {
        return m_fullWindowAppId;
    }

    const JValue& getForegroundInfo() const
    {
        return m_foregroundInfo;
    }

    const string &getEnvPulseServer() const
    {
        return m_envPulseServer;
    }

    const string &getEnvWaylandDisplay() const
    {
        return m_envWaylandDisplay;
    }

    const string &getEnvXdgRuntimeDir() const
    {
        return m_envXdgRuntimeDir;
    }

protected:
    // AbsLunaClient
    virtual void onInitialzed() override;
    virtual void onFinalized() override;
    virtual void onServerStatusChanged(bool isConnected) override;

private:
    static bool isFullscreenWindowType(const JValue& foreground_info);
    static bool onGetForegroundAppInfo(LSHandle* sh, LSMessage* message, void* context);
    static bool onGetAppLaunchEnvironment(LSHandle *sh, LSMessage *message, void *context);

    LSM();

    Call m_getForegroundAppInfoCall;
    Call m_getAppLaunchEnvironmentCall;

    string m_fullWindowAppId;
    vector<string> m_foregroundAppIds;
    JValue m_foregroundInfo;

    string m_envPulseServer;
    string m_envWaylandDisplay;
    string m_envXdgRuntimeDir;
};

#endif

