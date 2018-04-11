add_executable(compare compare.cpp)
INSTALL(TARGETS compare DESTINATION bin)

if(WIN32)
  set(EXE_NAME test_qinstrument.exe)
  set(COMPARE_EXE_NAME compare.exe)
else()
  set(EXE_NAME test_qinstrument)
  set(COMPARE_EXE_NAME compare)
endif()


foreach(ID RANGE 4)
add_Test(NAME test0${ID} COMMAND ${CMAKE_BINARY_DIR}/bin/${COMPARE_EXE_NAME} ${CMAKE_SOURCE_DIR}/tests/test0${ID}.wav ${CMAKE_BINARY_DIR}/tests/output${ID}-0.wav)

add_Test(NAME test0${ID}_harmonic1 COMMAND ${CMAKE_BINARY_DIR}/bin/${COMPARE_EXE_NAME} ${CMAKE_SOURCE_DIR}/tests/test0${ID}_harmonic1.wav ${CMAKE_BINARY_DIR}/tests/output${ID}-0_harmonic1.wav)

add_Test(NAME test0${ID}_harmonic2 COMMAND ${CMAKE_BINARY_DIR}/bin/${COMPARE_EXE_NAME} ${CMAKE_SOURCE_DIR}/tests/test0${ID}_harmonic2.wav ${CMAKE_BINARY_DIR}/tests/output${ID}-0_harmonic2.wav)

add_Test(NAME test0${ID}_harmonicboth COMMAND ${CMAKE_BINARY_DIR}/bin/${COMPARE_EXE_NAME} ${CMAKE_SOURCE_DIR}/tests/test0${ID}_harmonicboth.wav ${CMAKE_BINARY_DIR}/tests/output${ID}-0_harmonicboth.wav)

endforeach(ID)

add_Test(NAME test04_longer COMMAND ${CMAKE_BINARY_DIR}/bin/${COMPARE_EXE_NAME} ${CMAKE_SOURCE_DIR}/tests/test04_longer.wav ${CMAKE_BINARY_DIR}/tests/output4_longer-0.wav)

add_Test(NAME test04_velocity COMMAND ${CMAKE_BINARY_DIR}/bin/${COMPARE_EXE_NAME} ${CMAKE_SOURCE_DIR}/tests/test04_velocity.wav ${CMAKE_BINARY_DIR}/tests/output4_velocity-0.wav)

