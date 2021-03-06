// Copyright (c) 2015-2016 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0
// http://vittorioromeo.info | vittorio.romeo@outlook.com

#pragma once

#include <ecst/config.hpp>
#include <ecst/aliases.hpp>
#include "../split_evenly_fn.hpp"

ECST_INNER_PARALLELISM_STRATEGY_NAMESPACE
{
    namespace split_evenly
    {
        namespace impl
        {
            template <typename TSubtaskCount>
            struct v_subtask_count
            {
                auto operator()() const noexcept
                {
                    return TSubtaskCount{};
                }
            };
        }

        template <typename TSubtaskCount>
        constexpr auto v(TSubtaskCount)
        {
            return split_evenly_fn::v(impl::v_subtask_count<TSubtaskCount>{});
        }
    }
}
ECST_INNER_PARALLELISM_STRATEGY_NAMESPACE_END
