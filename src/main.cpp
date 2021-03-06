/*
 * main.cpp
 *
 * Copyright (C) 2014-2015  Ming Tsang, Nathan Ng
 * Refer to LICENSE for details
 */

#include <ctime>

#include <fstream>
#include <memory>

#if _WIN32
#include <windows.h>
#include <tchar.h>

#endif

#include <platform/CCApplication.h>

#include <libutils/io/basic_log_strategy.h>
#include <libutils/io/composite_log_strategy.h>
#include <libutils/io/js_html_log_strategy.h>
#include <libutils/io/logger.h>
#include <libutils/io/system_log.h>
#include <libutils/str/str_utils.h>

#include "log.h"
#include "mgirl_mica.h"

using namespace std;
using namespace utils::io;

namespace
{

void initLog()
{
#if !NO_LOG
	auto log_strategy = make_unique<CompositeLogStrategy<char>>();
	log_strategy->PushStrategy(make_unique<JsHtmlLogStrategy<char>>(
			new ofstream(utils::str::StrUtils::Concat("log-", time(nullptr),
					".html"))));
	log_strategy->PushStrategy(make_unique<BasicLogStrategy<char>>(&cout, false));
	LOG.SetLogStrategy(std::move(log_strategy));
#endif
}

}

#if __linux__
int main()
{
	initLog();
    mica::MgirlMica app;
    return cocos2d::Application::getInstance()->run();
}

#elif _WIN32
int APIENTRY _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
    // create the application instance
    mica::MgirlMica app;
    return cocos2d::Application::getInstance()->run();
}


#endif
