#ifndef MAP_H
#define MAP_H

#define NUM_TEMPLATES 4
#define BOUND 40

struct Map{
    char tiles[BOUND][BOUND];
};

struct Position{
    int x;
    int y;
    int z;
};

const char Tutorial[BOUND][BOUND] = {
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"#S   E F################################",
"########################################"    
};

const char map1[BOUND][BOUND] = {
"########################################",
"#                 #     # C#           0",
"# ### # #C# # ### # # # U ##           #",
"#U# ######### # U ### ###  #        E  #",
"# #         #####       ## #           #",
"# ## # # # E      ##### #  #           #",
"### U# # # ## # # #   #   ##           #",
"# #### ### ###### ### # ##C#           #",
"#C#    #       #    #U#    #           #",
"# # ##C#### ##### ### ### ##           #",
"#   #     # #  U  #C      #I           #",
"########### ############################",
"#HHHHHHHHHH                #C          F",
"#HHHHHHHHHH#### # # ### ####### ########",
"LHHHHHHHHHH#  # #C### # #  U  # #E   # #",
"#HHHHHHHHHH# ## ### U # ##### # ## # #C#",
"## # ####### #      ###     #      ### #",
"#  # #     U ########   ##### ####     #",
"####   ### # # # # #  #    U   # # # # #",
"# U  #   # # # # #U# ## # ### ## # ### #",
"# #### # ### #        #C#   #  #   # #U#",
"# #    #U#     # # # ######## ##U# # # #",
"### ## # ####        # #      #  # # ###",
"#     E     ## # # # # ### #######  U C#",
"# ### ### #       E  #U# #       ### ###",
"#C# # #   # ## # # # #   # ##  #C# # # #",
"### ### # #  #      ####   #C #### # # #",
"#       # # ##C # # ## # ####  #     # #",
"# ####### ##    # ###C #    # ###### # #",
"# #  #     ######  C# #######        E #",
"# ##   ###      # # # # # # # # ###### #",
"# C# ###C## #U# #   #         # # C  # #",
"#  # #          ## ### #### ### # ## # #",
"#### ###### ###      ###  # #   # #  # #",
"#  U      #     ####      #U# # # #### #",
"# ## ## # # ### # C# #### # # # #HHHHHH#",
"#  # #W # # # # # ##  E # # # #C#HHHHHH#",
"#### #### ### # #    ## # ### ###HHHHHH#",
"#S          U # # # ##C #  U    #HHHHHH#",
"########################################"
};

const char map2[BOUND][BOUND] = {
"########################################",
"#      # # #    # # # # # #     ###    0",
"# ####   # #### #         # ###   #### #",
"#  # ##      #  # ### ### # # ###      #",
"# ## #  ### ### #   #   # # #   # ## # #",
"# #  ####       # ### ##### ### # ## # #",
"# ## #   ## # # # #             #    # #",
"#    # # #### ### ## ### ## ########## #",
"# #### #    # # #  # #        #    #   #",
"#  # ### # ##   #### #### # # #### # ###",
"##       #  # # #I      #              #",
"############### ########################",
"#HHH# # # # #   #                #     F",
"#HHH        # # # # ### ## # # # ##### #",
"LHHH### ####### # # # ############ # # #",
"#HHH#           # ###    #  #   #  # # #",
"# ##### ### # # #   #### ## # # # ## # #",
"#  #  #   ####### ###  # ## # #   #    #",
"# ### ##### #       ##          # #### #",
"#             # # ###  ######## #      #",
"# ###### ### ###### ## #   ## #   #### #",
"### ##   #   #      #  ###    # #    # #",
"#      ##### # ### ###   # ########### #",
"###### #   ##### #   ## ## # # # # # # #",
"#   #  ### #   # # #                   #",
"## ### #   # # # ### # # # # ### #######",
"#      # # ### #     # # # #      # #  #",
"# ########      ######## # # # # ##   ##",
"#  #        # ##     # # ### # #  # #  #",
"# ##### ### # #  # # # #   # #### # # ##",
"# #   # # # #### # #     ###        #  #",
"### # # # #      ### # #     ## ### ####",
"#   # # # # # ##     #####   #         #",
"# ###   # #    # # # # # # #### ### ####",
"# #   ### # # ## ### #   # #     #### ##",
"# ### #                ###   ### #HHHHH#",
"#   # # # # # ## ### ###   # # # #HHHHH#",
"# ### #       #  # #   ### ### ###HHHHH#",
"#S#   # # # # ##     # #          HHHHH#",
"########################################"
};

const char map3[BOUND][BOUND] = {
"########################################",
"###       ##  # #                      0",
"#   # # #    ## # ### ##### ## ##### # #",
"############  # # #     #   #   #    ###",
"#     #      ## # # # # ## ####### #   #",
"# ### #### #    # #######   #  # ### # #",
"# # #    ### ####    # #  # ##       # #",
"# #   ##        # ##   ######  ###  ####",
"# ########## ##   #  # #   #  ## ##    #",
"# # #   ## # #  #### ##### ####   # ####",
"#I#   #      # ##    #          #     ##",
"########################################",
"#HHHH#                    # # #        F",
"#HHHH######### ### ######## # # ### ####",
"LHHHH        # # #     #    # # # # #  #",
"######### ## # # ##### #### # # ### ## #",
"#    #         #              #   #  # #",
"# ##### # ######## # # ######## ###### #",
"# #     ####  #  # # # ##     #        #",
"# #####            # #    # ########## #",
"#   #   # # # ### #######   #        # #",
"# ##### ### ### ### #     # # # ###### #",
"# #                 # ### # # #   #    #",
"# ### # ### ### #####   # # # # ###### #",
"# # ### # # # # #     # ##### # #    # #",
"#             # ### ###         # # ## #",
"######### ##### # ### ### # ### # #    #",
"#           #     #   #   #   #   ###  #",
"# ### ##### ### ### ### #### ## # # # ##",
"#  #  #       # # # # #       #   #    #",
"####### # #  ##   #     # # # ##### # ##",
"# #       #   ########### # #     # #  #",
"#   # # # ## ##       ##  # # ### # ####",
"#####      #    # # #    #######  # #  #",
"#     ### ######### #### # #   # ## # ##",
"# ### #    #         # # # # ###       #",
"# # # ### #### # # ###         ### ## ##",
"# #     # #    # # # # # # # ### ###HHH#",
"#S# # # # #### #     #              HHH#",
"########################################"
};

const char map4[BOUND][BOUND] = {
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"########################################",
"#S                                  E F#",
"########################################"    
};

#endif