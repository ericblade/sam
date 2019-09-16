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

#ifndef DB_HANDLER_4_BASE_H
#define DB_HANDLER_4_BASE_H

#include <launchpoint/handler/DBHandler.h>
#include "interface/IClassName.h"
#include <pbnjson.hpp>
#include <boost/signals2.hpp>
#include "util/Logger.h"

class DBHandler : public IClassName {
public:
    DBHandler();
    virtual ~DBHandler();

    virtual void init();
    virtual void handleDbState(bool connection);
    virtual void reloadDbData(bool connection);

    virtual bool insertData(const pbnjson::JValue& json);
    virtual bool updateData(const pbnjson::JValue& json);
    virtual bool deleteData(const pbnjson::JValue& json);

    boost::signals2::signal<void (const pbnjson::JValue&)> EventDBLoaded_;

private:
    void onLaunchPointDbLoaded(const pbnjson::JValue& loaded_db_result);

    bool m_isDBLoaded;
    unsigned int m_DBLoadCount;

};

#endif
