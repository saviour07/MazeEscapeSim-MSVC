#include <string>
#include <sstream>
#include <iostream>
#include "Player/player.h"
#include "Maze/maze.h"
#include "consolelogger.h"

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
    logger.WriteLine(startYMsg.str());
    
    std::wstringstream startXMsg;
    startXMsg << L"Start X: " << startPosition.X;
    logger.WriteLine(startXMsg.str());

    if (Simulate(logger, maze, player))
    {
        logger.WriteLine(L"Out");
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
        logger.WriteLine(turnMsg.str());
        const auto position = player.MoveDirection(maze.Rows);

        std::wstringstream newYPosMsg;
        newYPosMsg << L"New Y Pos: " << position.Y;
        logger.WriteLine(newYPosMsg.str());

        std::wstringstream newXPosMsg;
        newXPosMsg << L"New X Pos: " << position.X;
        logger.WriteLine(newXPosMsg.str());

        logger.WriteLine(L"================================");
    }
    return true;
}