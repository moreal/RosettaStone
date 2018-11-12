// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef HEARTHSTONEPP_DRAW_TASK_H
#define HEARTHSTONEPP_DRAW_TASK_H

#include <hspp/Tasks/TaskAgent.h>
#include <hspp/Tasks/Tasks.h>

namespace Hearthstonepp::BasicTasks
{
//!
//! \brief DrawTask class.
//!
//! This class represents the task for drawing card(s) from deck at random.
//!
class DrawTask : public ITask
{
 public:
    //! Constructs task with given \p agent and \p num.
    //! \param agent The task agent that notifies overdrawn cards.
    //! \param num The number of cards to draw.
    DrawTask(Player& player, size_t num);

    //! Returns task ID.
    //! \return Task ID.
    TaskID GetTaskID() const override;

 private:
    //! Processes task logic internally and returns meta data.
    //! \param player1 The first player.
    //! \param player2 The second player.
    //! \return The result of task processing.
    MetaData Impl(Player& player1, Player& player2) override;

    Player& m_player;
    size_t m_num = 0;
};

//!
//! \brief DrawCardTask class.
//!
//! This class represents the task for drawing specified card from deck.
//!
class DrawCardTask : public ITask
{
 public:
    //! Constructs task with given \p card.
    //! \param card A card to draw from deck.
    DrawCardTask(Card card);

    //! Returns task ID.
    //! \return Task ID.
    TaskID GetTaskID() const override;

 private:
    //! Processes task logic internally and returns meta data.
    //! \param player1 The first player.
    //! \param player2 The second player.
    //! \return The result of task processing.
    MetaData Impl(Player& player1, Player& player2) override;

    Card m_card;
};
}  // namespace Hearthstonepp::BasicTasks

#endif  // HEARTHSTONEPP_DRAW_TASK_H
