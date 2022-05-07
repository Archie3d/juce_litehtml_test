set(TARGET browser)

juce_add_gui_app(${TARGET}
    PRODUCT_NAME "Browser"
    VERSION "1.0.0"
)

target_link_libraries(${TARGET}
    PRIVATE
        juce::juce_core
        juce::juce_core
        juce::juce_data_structures
        juce::juce_gui_basics

        juce::juce_litehtml

        juce::juce_recommended_config_flags
)

juce_generate_juce_header(${TARGET})

set(src
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/Main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/WebHistory.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/WebHistory.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/MainComponent.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/MainComponent.cpp
)

target_sources(${TARGET} PRIVATE ${src})

target_compile_definitions(${TARGET}
    PRIVATE
        JUCE_DISPLAY_SPLASH_SCREEN=0
        JUCE_ENABLE_REPAINT_DEBUGGING=0
)
