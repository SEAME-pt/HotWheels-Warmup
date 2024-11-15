include(/home/programming-pc/seame/warm-up/Modules/Module03/Phonebook/build/Desktop_Qt_6_8_0-Debug/.qt/QtDeploySupport.cmake)
include("${CMAKE_CURRENT_LIST_DIR}/Phonebook-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE /home/programming-pc/seame/warm-up/Modules/Module03/Phonebook/build/Desktop_Qt_6_8_0-Debug/Phonebook
    GENERATE_QT_CONF
)
