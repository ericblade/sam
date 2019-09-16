// Copyright (c) 2017-2019 LG Electronics, Inc.
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

#ifndef LAUNCH_POINT_BOOKMARK_4_BASE_H
#define LAUNCH_POINT_BOOKMARK_4_BASE_H

#include <launchpoint/launch_point/LaunchPoint.h>

class LaunchPointBookmark: public LaunchPoint {
public:
    LaunchPointBookmark(const std::string& appId, const std::string& launchPointId)
        : LaunchPoint(appId, launchPointId)
    {
    }

    static LaunchPointPtr create(const std::string& launchPointId, const pbnjson::JValue& data, std::string& errorText);
    virtual std::string update(const pbnjson::JValue& data);
};

#endif /* LAUNCH_POINT_BOOKMARK_4_BASE_H */
