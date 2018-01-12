add_executable(Interstellor main.cpp Animation.h Animation.cpp classBullet.h classEntity.h classPlayer.h classStones.h classAlienship.h Timer.h )
                                                                                                 
target_include_directories(Interstellor PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(Interstellor PUBLIC cxx_std_17)
target_compile_definitions(Interstellor PRIVATE SFML_STATIC)

target_link_libraries(Interstellor ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
