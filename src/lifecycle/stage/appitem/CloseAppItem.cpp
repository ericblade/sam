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

#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <lifecycle/stage/appitem/CloseAppItem.h>
#include <package/AppPackageManager.h>

CloseAppItem::CloseAppItem(const std::string& appId, const std::string& pid, const std::string& caller, const std::string& reason)
    : AppItem(appId, "", pid)
{
    setReason(reason);
    setCallerId(caller);

    Logger::info("CloseAppItem", __FUNCTION__, getUid(), "created_close_item");
}

CloseAppItem::~CloseAppItem()
{
    Logger::info("CloseAppItem", __FUNCTION__, getUid(), "removed_close_item");
}
