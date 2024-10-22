
# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.

b1s1_llama2_providers = ['W$_{FP16}$A$_{FP16}$', 'W$_{INT4}$A$_{FP16}$', 'W$_{MXFP8}$A$_{MXFP8}$', 'W$_{INT1}$A$_{INT8}$']
b1s1_llama2_times_data = [('Welder-Roller', [2.173171, 0, 0, 0]), ('+Transform', [3.6213727473914625, 0.5670661075052786, 2.409120546507835, 0.3795013932154188]), ('+PTX', [1.9808059364259243, 0.600685312041359, 2.4046726467490194, 0.21382991612112617]), ('+Holistic Schedule', [1.982, 0.59439808, 1.1918, 0.207486801])]

b1s4096_llama2_providers = ['W$_{FP16}$A$_{FP16}$', 'W$_{INT4}$A$_{FP16}$', 'W$_{MXFP8}$A$_{MXFP8}$', 'W$_{INT1}$A$_{INT8}$']
b1s4096_llama2_times_data = [('Welder-Roller', [254.423248, 0, 0, 0]), ('+Transform', [165.0225958881378, 193.40398650045046, 2186.287296295166, 556.9458051256591]), ('+PTX', [100.37787104225158, 88.11384849424012, 2186.287296295166, 559.9500032]), ('+Holistic Schedule', [98.8685, 97.91209607, 699.8160501, 559.9500032])]
