cmake_minimum_required(VERSION 3.15)
project(RasterEngine)

# Настройка SDL2
set(SDL_STATIC OFF CACHE BOOL "" FORCE)
set(SDL_SHARED ON CACHE BOOL "" FORCE)
add_subdirectory(libs/SDL)

include_directories(
    libs/SDL/include
    include
)

# Создание исполняемого файла
add_executable(${PROJECT_NAME}
    src/RasterEngine/ColorBuffer.cpp
    src/RasterEngine/Context.cpp
    src/RasterEngine/EventSys.cpp
    src/RasterEngine/Renderer.cpp
    src/RasterEngine/Window.cpp
    src/RasterEngine/Grid.cpp
    src/RasterEngine/Rect.cpp
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE 
    SDL2main
    SDL2
    -Wl,--undefined=WinMain  # Явное указание точки входа
    -static-libgcc
    -static-libstdc++
)

# Копирование DLL
if(WIN32 AND NOT SDL_STATIC)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:SDL2>
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
        COMMENT "Copying SDL2.dll to output directory"
    )
endif()