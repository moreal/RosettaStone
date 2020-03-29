// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef ROSSETASTONE_ROSETTA_HPP
#define ROSSETASTONE_ROSETTA_HPP

#include <Rosetta/Accounts/AccountInfo.hpp>
#include <Rosetta/Accounts/DeckInfo.hpp>
#include <Rosetta/Actions/ActionApplyHelper.hpp>
#include <Rosetta/Actions/ActionChoices.hpp>
#include <Rosetta/Actions/ActionParams.hpp>
#include <Rosetta/Actions/ActionTargets.hpp>
#include <Rosetta/Actions/ActionValidChecker.hpp>
#include <Rosetta/Actions/ActionValidGetter.hpp>
#include <Rosetta/Actions/Attack.hpp>
#include <Rosetta/Actions/CastSpell.hpp>
#include <Rosetta/Actions/Choices/ChooseFromCardIDs.hpp>
#include <Rosetta/Actions/Choices/ChooseFromNumbers.hpp>
#include <Rosetta/Actions/Choices/InvalidChoice.hpp>
#include <Rosetta/Actions/Choose.hpp>
#include <Rosetta/Actions/Copy.hpp>
#include <Rosetta/Actions/Draw.hpp>
#include <Rosetta/Actions/Generic.hpp>
#include <Rosetta/Actions/PlayCard.hpp>
#include <Rosetta/Actions/Summon.hpp>
#include <Rosetta/Auras/AdaptiveCostEffect.hpp>
#include <Rosetta/Auras/AdaptiveEffect.hpp>
#include <Rosetta/Auras/AdjacentAura.hpp>
#include <Rosetta/Auras/Aura.hpp>
#include <Rosetta/Auras/AuraUpdateInstruction.hpp>
#include <Rosetta/Auras/EnrageEffect.hpp>
#include <Rosetta/Auras/IAura.hpp>
#include <Rosetta/Auras/SummoningPortalAura.hpp>
#include <Rosetta/Auras/SwitchingAura.hpp>
#include <Rosetta/CardSets/BlackTempleCardsGen.hpp>
#include <Rosetta/CardSets/CoreCardsGen.hpp>
#include <Rosetta/CardSets/DalaranCardsGen.hpp>
#include <Rosetta/CardSets/DragonsCardsGen.hpp>
#include <Rosetta/CardSets/Expert1CardsGen.hpp>
#include <Rosetta/CardSets/HoFCardsGen.hpp>
#include <Rosetta/CardSets/UldumCardsGen.hpp>
#include <Rosetta/CardSets/YoDCardsGen.hpp>
#include <Rosetta/Cards/Card.hpp>
#include <Rosetta/Cards/CardDef.hpp>
#include <Rosetta/Cards/CardDefs.hpp>
#include <Rosetta/Cards/Cards.hpp>
#include <Rosetta/Commons/Constants.hpp>
#include <Rosetta/Commons/DeckCode.hpp>
#include <Rosetta/Commons/JSONSerializer.hpp>
#include <Rosetta/Commons/Macros.hpp>
#include <Rosetta/Commons/PriorityQueue.hpp>
#include <Rosetta/Commons/SpinLocks.hpp>
#include <Rosetta/Commons/Utils.hpp>
#include <Rosetta/Conditions/RelaCondition.hpp>
#include <Rosetta/Conditions/SelfCondition.hpp>
#include <Rosetta/Enchants/Attrs/Atk.hpp>
#include <Rosetta/Enchants/Attrs/Attr.hpp>
#include <Rosetta/Enchants/Attrs/BoolAttr.hpp>
#include <Rosetta/Enchants/Attrs/Cost.hpp>
#include <Rosetta/Enchants/Attrs/Health.hpp>
#include <Rosetta/Enchants/Attrs/IntAttr.hpp>
#include <Rosetta/Enchants/Attrs/SelfContainedBoolAttr.hpp>
#include <Rosetta/Enchants/Attrs/SelfContainedIntAttr.hpp>
#include <Rosetta/Enchants/AuraEffects.hpp>
#include <Rosetta/Enchants/Effect.hpp>
#include <Rosetta/Enchants/Effects.hpp>
#include <Rosetta/Enchants/Enchant.hpp>
#include <Rosetta/Enchants/Enchants.hpp>
#include <Rosetta/Enchants/GenericEffect.hpp>
#include <Rosetta/Enchants/IEffect.hpp>
#include <Rosetta/Enchants/OngoingEnchant.hpp>
#include <Rosetta/Enchants/PlayerAuraEffects.hpp>
#include <Rosetta/Enchants/Power.hpp>
#include <Rosetta/Enchants/SwapCostEnchant.hpp>
#include <Rosetta/Enums/ActionEnums.hpp>
#include <Rosetta/Enums/AuraEnums.hpp>
#include <Rosetta/Enums/CardEnums.hpp>
#include <Rosetta/Enums/GameEnums.hpp>
#include <Rosetta/Enums/TargetingEnums.hpp>
#include <Rosetta/Enums/TaskEnums.hpp>
#include <Rosetta/Enums/TriggerEnums.hpp>
#include <Rosetta/Games/Game.hpp>
#include <Rosetta/Games/GameConfig.hpp>
#include <Rosetta/Games/GameRestorer.hpp>
#include <Rosetta/Loaders/AccountLoader.hpp>
#include <Rosetta/Loaders/CardLoader.hpp>
#include <Rosetta/Loaders/InternalCardLoader.hpp>
#include <Rosetta/Loaders/TargetingPredicates.hpp>
#include <Rosetta/Managers/CostManager.hpp>
#include <Rosetta/Managers/GameManager.hpp>
#include <Rosetta/Managers/TriggerEvent.hpp>
#include <Rosetta/Managers/TriggerEventHandler.hpp>
#include <Rosetta/Managers/TriggerManager.hpp>
#include <Rosetta/Models/Character.hpp>
#include <Rosetta/Models/Choice.hpp>
#include <Rosetta/Models/Enchantment.hpp>
#include <Rosetta/Models/Entity.hpp>
#include <Rosetta/Models/Hero.hpp>
#include <Rosetta/Models/HeroPower.hpp>
#include <Rosetta/Models/Minion.hpp>
#include <Rosetta/Models/Playable.hpp>
#include <Rosetta/Models/Player.hpp>
#include <Rosetta/Models/Spell.hpp>
#include <Rosetta/Models/Weapon.hpp>
#include <Rosetta/RosettaStone.hpp>
#include <Rosetta/Tasks/EventMetaData.hpp>
#include <Rosetta/Tasks/ITask.hpp>
#include <Rosetta/Tasks/PlayerTasks/AttackTask.hpp>
#include <Rosetta/Tasks/PlayerTasks/ChooseTask.hpp>
#include <Rosetta/Tasks/PlayerTasks/EndTurnTask.hpp>
#include <Rosetta/Tasks/PlayerTasks/HeroPowerTask.hpp>
#include <Rosetta/Tasks/PlayerTasks/PlayCardTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/ActivateCapturedDeathrattleTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/AddAuraEffectTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/AddCardTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/AddEnchantmentTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/AddLackeyTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/AddStackToTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/ArmorTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/AttackTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/ChanceTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/ChangeAttackingTargetTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/ChangeEntityTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/ChangeHeroPowerTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/ClearStackTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/ConditionTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/ControlTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/CopyTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/CountTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/CustomTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/DamageNumberTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/DamageTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/DamageWeaponTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/DestroyAllTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/DestroyTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/DiscardTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/DiscoverTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/DrawNumberTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/DrawOpTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/DrawStackTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/DrawTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/EnqueueNumberTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/EnqueueTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/FilterStackTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/FlagTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/FuncNumberTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/FuncPlayableTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/GetEventNumberTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/GetGameTagTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/GetPlayerGameTagTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/HealFullTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/HealTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/IncludeAdjacentTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/IncludeTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/InvokeTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/ManaCrystalTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/MathAddTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/MathMultiplyTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/MathNumberIndexTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/MathSubtractTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/MoveToGraveyardTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/MoveToSetasideTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/NumberConditionTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/QuestProgressTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/RandomCardTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/RandomEntourageTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/RandomMinionTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/RandomSpellTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/RandomTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/RemoveDurabilityTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/RemoveEnchantmentTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/RemoveHandTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/ReplaceHeroTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/ReturnHandTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/RevealStealthTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/SetGameTagNumberTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/SetGameTagTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/SilenceTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/SummonCapturedMinionTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/SummonCopyTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/SummonOpTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/SummonStackTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/SummonTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/SwapAttackHealthTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/SwapHeroPowerTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/TempManaTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/TransformCopyTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/TransformTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/WeaponTask.hpp>
#include <Rosetta/Tasks/TaskQueue.hpp>
#include <Rosetta/Tasks/TaskStack.hpp>
#include <Rosetta/Tasks/TaskStatus.hpp>
#include <Rosetta/Triggers/MultiTrigger.hpp>
#include <Rosetta/Triggers/Trigger.hpp>
#include <Rosetta/Triggers/Triggers.hpp>
#include <Rosetta/Views/Board.hpp>
#include <Rosetta/Views/BoardRefView.hpp>
#include <Rosetta/Views/BoardView.hpp>
#include <Rosetta/Views/ReducedBoardView.hpp>
#include <Rosetta/Views/Types/CardInfo.hpp>
#include <Rosetta/Views/Types/Player.hpp>
#include <Rosetta/Views/Types/UnknownCards.hpp>
#include <Rosetta/Views/ViewTypes.hpp>
#include <Rosetta/Zones/DeckZone.hpp>
#include <Rosetta/Zones/FieldZone.hpp>
#include <Rosetta/Zones/GraveyardZone.hpp>
#include <Rosetta/Zones/HandZone.hpp>
#include <Rosetta/Zones/IZone.hpp>
#include <Rosetta/Zones/SecretZone.hpp>
#include <Rosetta/Zones/SetasideZone.hpp>
#include <Rosetta/Zones/Zone.hpp>

#endif  // ROSSETASTONE_ROSETTA_HPP
