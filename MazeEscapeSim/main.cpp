#include <string>
#include <sstream>
#include <iostream>
#include "Player/player.h"
#include "Maze/maze.h"
#include "Logger/consolelogger.h"

bool Simulate(mes_ilogger::ILogger& logger, mes_maze::Maze& maze, mes_player::Player player);

int main()
{
    mes_consolelogger::ConsoleLogger logger;

    mes_maze::Maze maze(logger, 10, 10);
    maze.GenerateMaze();

    mes_player::Player player(logger);
    const auto& startPosition = player.StartPosition(maze.RowCount(), maze.ColCount());

    std::wstringstream startYMsg;
    startYMsg << "Start Y: " << startPosition.Y;
    logger.Write(startYMsg.str(), true);
    
    std::wstringstream startXMsg;
    startXMsg << L"Start X: " << startPosition.X;
    logger.Write(startXMsg.str(), true);

    if (Simulate(logger, maze, player))
    {
        logger.Write(L"Out", true);
    }

    return 0;
}

bool Simulate(mes_ilogger::ILogger& logger, mes_maze::Maze& maze, mes_player::Player player)
{
    int turn = 0;
    while (!player.IsOutsideMaze(maze.Rows))
    {
        std::wstringstream turnMsg;
        turnMsg << L"Turn: " << std::to_wstring(++turn);
        logger.Write(turnMsg.str(), true);
        const auto position = player.MoveDirection(maze.Rows);

        std::wstringstream newYPosMsg;
        newYPosMsg << L"New Y Pos: " << position.Y;
        logger.Write(newYPosMsg.str(), true);

        std::wstringstream newXPosMsg;
        newXPosMsg << L"New X Pos: " << position.X;
        logger.Write(newXPosMsg.str(), true);

        logger.Write(L"================================", true);
    }
    return true;
}