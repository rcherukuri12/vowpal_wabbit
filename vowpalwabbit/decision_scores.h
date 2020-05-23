
// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.

#pragma once

#include "v_array.h"
#include "io/io_adapter.h"
#include <iomanip>
#include <iostream>
#include <vector>

namespace ACTION_SCORE
{
  struct action_score;
  typedef v_array<action_score> action_scores;
}

struct vw;
struct example;

namespace VW
{
// Each position in outer array is implicitly the decision corresponding to that index. Each inner array is the result
// of CB for that call.
using decision_scores_t = v_array<ACTION_SCORE::action_scores>;

void print_decision_scores(VW::io::writer* f, const VW::decision_scores_t& decision_scores);
void delete_decision_scores(void* polypred);

void print_update_ccb(vw& all, std::vector<example*>& slots, const VW::decision_scores_t& decision_scores, size_t num_features);
void print_update_slates(vw& all, std::vector<example*>& slots, const VW::decision_scores_t& decision_scores, size_t num_features);
}
