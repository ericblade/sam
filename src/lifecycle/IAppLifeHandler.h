// Copyright (c) 2012-2019 LG Electronics, Inc.
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

#ifndef APP_LIFE_HANDLER_INTERFACE_H_
#define APP_LIFE_HANDLER_INTERFACE_H_

#include <boost/signals2.hpp>
#include <lifecycle/ApplicationErrors.h>
#include <lifecycle/RunningInfo.h>
#include <lifecycle/stage/appitem/CloseAppItem.h>
#include <lifecycle/stage/appitem/LaunchAppItem.h>

class IAppLifeHandler {
public:
    IAppLifeHandler()
    {
    }
    virtual ~IAppLifeHandler()
    {
    }

    virtual void launch(LaunchAppItemPtr item) = 0;
    virtual void close(CloseAppItemPtr item, std::string& errorText) = 0;
    virtual void pause(const std::string& appId, const pbnjson::JValue& params, std::string& errorText, bool send_life_event = true) = 0;
};

#endif
