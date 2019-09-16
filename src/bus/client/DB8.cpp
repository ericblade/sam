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

#include <bus/client/DB8.h>
#include <util/Logger.h>
#include <bus/service/ApplicationManager.h>

const std::string DB8::WEBOS_SERVICE_DB = "com.webos.service.db";

DB8::DB8()
    : AbsLunaClient(WEBOS_SERVICE_DB)
{
}

DB8::~DB8()
{
}

void DB8::onInitialze()
{

}

void DB8::onServerStatusChanged(bool isConnected)
{

}

Call DB8::find(LSFilterFunc func, const string& name)
{
    static string method = std::string("luna://") + getName() + std::string("/find");

    JValue requestPayload = pbnjson::Object();
    requestPayload.put("query", pbnjson::Object());
    requestPayload["query"].put("from", name);
    requestPayload["query"].put("orderBy", "_rev");

    Call call = ApplicationManager::getInstance().callOneReply(method.c_str(), requestPayload.stringify().c_str(), func, nullptr);
    return call;
}

Call DB8::putKind(LSFilterFunc func, JValue& requestPayload)
{
    static string method = std::string("luna://") + getName() + std::string("/putKind");

    Call call = ApplicationManager::getInstance().callOneReply(method.c_str(), requestPayload.stringify().c_str(), func, nullptr);
    return call;
}

Call DB8::putPermissions(LSFilterFunc func, JValue& requestPayload)
{
    static string method = std::string("luna://") + getName() + std::string("/putPermissions");

    Call call = ApplicationManager::getInstance().callOneReply(method.c_str(), requestPayload.stringify().c_str(), func, nullptr);
    return call;
}
