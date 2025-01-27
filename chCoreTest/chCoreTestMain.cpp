#include "chBaseApplication.h"
#include "chDebug.h"
#include "chPath.h"

#include <format>

using namespace chEngineSDK;

int main(int argc, char** argv) {
  try {
    BaseApplication::startUp();
    auto& app = BaseApplication::instance();
    app.initialize(argc, argv);
    app.run();
    BaseApplication::shutDown();
  }
  catch(const std::exception& e)
  {
    LOG_ERROR(e.what());
    
    g_Debug().saveLog("resources/engine/logs/CRASHED_chCoreTestMain.txt");
    g_Debug().saveLogAsHtml("resources/engine/logs/CRASHED_chCoreTestMain.html");
    return 0;
  }

  g_Debug().saveLog("resources/engine/logs/chCoreTestMain.txt");
  return 1;
}
