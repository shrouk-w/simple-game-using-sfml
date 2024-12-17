cmake_minimum_required(VERSION 3.28)
project(totallynotisacclone)

set(CMAKE_CXX_STANDARD 20)
set(BUILD_SHARED_LIBS false)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)

FetchContent_MakeAvailable(SFML)

add_executable(totallynotisacclone main.cpp
        Classes/Player.cpp
        Classes/Player.h
        Classes/MultiuseFunctionsLib.cpp
        Classes/MultiuseFunctionsLib.h
        Classes/Enemy.cpp
        Classes/Enemy.h
        Classes/simpleEnemy.cpp
        Classes/simpleEnemy.h
        Classes/Bullet.cpp
        Classes/Bullet.h
        Classes/simpleEnemyBullet.cpp
        Classes/simpleEnemyBullet.h
        Classes/playerBullet.cpp
        Classes/playerBullet.h
        Classes/Room.cpp
        Classes/Room.h
        Classes/RoomSnipers.cpp
        Classes/RoomSnipers.h
        Classes/sniperEnemy.cpp
        Classes/sniperEnemy.h
        Classes/sniperEnemyBullet.cpp
        Classes/sniperEnemyBullet.h
        Classes/fatenemy.cpp
        Classes/fatenemy.h
        Classes/fatEnemyBullet.cpp
        Classes/fatEnemyBullet.h
        Classes/microvaweEnemyBullet.cpp
        Classes/microvaweEnemyBullet.h
        Classes/microwaveenemy.cpp
        Classes/microwaveenemy.h
        Classes/RoomSimples.cpp
        Classes/RoomSimples.h
        Classes/RoomFatMicorwave.cpp
        Classes/RoomFatMicorwave.h
        Classes/RoomUpgrade.cpp
        Classes/RoomUpgrade.h
        Classes/RoomMicroWaveRush.cpp
        Classes/RoomMicroWaveRush.h
        Classes/RoomFat.cpp
        Classes/RoomFat.h
        Classes/RoomBoss.cpp
        Classes/RoomBoss.h
        Classes/bossenemy.cpp
        Classes/bossenemy.h
        Classes/Item.cpp
        Classes/Item.h
        Classes/ItemBigDmg.cpp
        Classes/ItemBigDmg.h
        Classes/ItemWand.cpp
        Classes/ItemWand.h
        Classes/Item4Directions.cpp
        Classes/Item4Directions.h
        Classes/SpinTrapBullet.cpp
        Classes/SpinTrapBullet.h
        Classes/ItemSpinTrap.cpp
        Classes/ItemSpinTrap.h
        Classes/RandomDirectionBullet.cpp
        Classes/RandomDirectionBullet.h
        Classes/ItemRandomizeDirection.cpp
        Classes/ItemRandomizeDirection.h
        Classes/ItemSniperRifle.cpp
        Classes/ItemSniperRifle.h
        Classes/Gui.cpp
        Classes/Gui.h
)

target_link_libraries(totallynotisacclone sfml-graphics)