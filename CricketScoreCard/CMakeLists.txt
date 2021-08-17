cmake_minimum_required(VERSION 3.19)
project(CricketScoreCard)

set(CMAKE_CXX_STANDARD 14)

add_executable(CricketScoreCard main.cpp player.h team.h match.h runs.h over.h mapping.h winnerCalculator.h runCalculator.h)