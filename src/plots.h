/* File: plots.h */

/* Purpose: extern plots declarations */

extern bool_ quest_null_hook(int q);

/******* Random Quests ********/
extern bool_ is_randhero(int level);
extern bool_ quest_random_init_hook(int q_idx);
extern bool_ quest_random_describe(FILE *fff);

/******* Plot main ********/
extern bool_ quest_necro_init_hook(int q_idx);
extern bool_ quest_one_init_hook(int q_idx);
extern bool_ quest_sauron_init_hook(int q_idx);
extern bool_ quest_morgoth_init_hook(int q_idx);
extern bool_ quest_ultra_good_init_hook(int q_idx);
extern bool_ quest_ultra_evil_init_hook(int q_idx);

/******* Plot Bree *********/
extern bool_ quest_thieves_init_hook(int q_idx);
extern bool_ quest_hobbit_init_hook(int q_idx);
extern bool_ quest_troll_init_hook(int q_idx);
extern bool_ quest_wight_init_hook(int q_idx);
extern bool_ quest_nazgul_init_hook(int q_idx);
extern bool_ quest_shroom_init_hook(int q_idx);

/******* Plot Lorien *********/
extern bool_ quest_wolves_init_hook(int q_idx);
extern bool_ quest_spider_init_hook(int q_idx);
extern bool_ quest_poison_init_hook(int q_idx);

/******* Plot Gondolin *********/
extern bool_ quest_dragons_init_hook(int q_idx);
extern bool_ quest_eol_init_hook(int q_idx);
extern bool_ quest_nirnaeth_init_hook(int q_idx);
extern bool_ quest_invasion_init_hook(int q_idx);

/******* Plot Minas Anor *********/
extern bool_ quest_haunted_init_hook(int q_idx);
extern bool_ quest_between_init_hook(int q_idx);

/******* Plot Khazad-dum *********/
extern bool_ quest_evil_init_hook(int q_idx);

/******* Plot Other *********/
extern bool_ quest_narsil_init_hook(int q_idx);
extern bool_ quest_thrain_init_hook(int q_idx);
