add_library(vanguard STATIC
    VanguardSettingsWrapper.h
    VanguardClient.h
    VanguardClient.cpp
)

SET_TARGET_PROPERTIES(vanguard PROPERTIES LINK_FLAGS "/CLRTHREADATTRIBUTE:STA")


file(GLOB CLR_FILES
    VanguardSettingsWrapper.h
    VanguardSettings.cpp
    VanguardClient.h
    VanguardClient.cpp
)
set_source_files_properties(${CLR_FILES} PROPERTIES COMPILE_FLAGS "/clr /EHa /Zc:twoPhase-")
set_target_properties(vanguard PROPERTIES VS_DOTNET_REFERENCES_COPY_LOCAL ON )
set_target_properties(vanguard PROPERTIES DOTNET_TARGET_FRAMEWORK_VERSION "v4.7.1")
set_target_properties(vanguard PROPERTIES VS_DOTNET_REFERENCE_CorruptCore "${PROJECT_SOURCE_DIR}/../../../RTCV/Build/CorruptCore.dll")
set_target_properties(vanguard PROPERTIES VS_DOTNET_REFERENCE_NetCore "${PROJECT_SOURCE_DIR}/../../../RTCV/Build/NetCore.dll")
set_target_properties(vanguard PROPERTIES VS_DOTNET_REFERENCE_RTCVCommon "${PROJECT_SOURCE_DIR}/../../../RTCV/Build/RTCV.Common.dll")
set_target_properties(vanguard PROPERTIES VS_DOTNET_REFERENCE_Vanguard "${PROJECT_SOURCE_DIR}/../../../RTCV/Build/Vanguard.dll")
set_target_properties(vanguard PROPERTIES VS_DOTNET_REFERENCES "System;System.Windows.Forms")
string(REGEX REPLACE "/RTC(su|[1su])" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
string(REGEX REPLACE "/RTC(su|[1su])" "" CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")


target_link_libraries(vanguard PUBLIC vanguardwrapper common )
target_link_libraries(vanguard PUBLIC Boost::boost PRIVATE Boost::serialization)