# !/bin/bash
# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.

# AMOS_HOME = pwd home + .. + .. + .. + 3rdparty + AMOS
export AMOS_HOME=$(pwd)/../../baseline_framework/AMOS
export PYTHONPATH=$AMOS_HOME/python
pip install xgboost==1.5.0

force_tune=0
if [[ "$1" == "--force_tune" ]]; then
    force_tune=1
fi

echo "[AMOS] Using checkpoint path: $CHECKPOINT_PATH"

AMOS_LOG_PATH="$CHECKPOINT_PATH/amos/logs"
if [ -d "$AMOS_LOG_PATH" ]; then
    echo "[AMOS] Log directory already exists in checkpoints directory. Copying to current directory..."
    cp -r "$AMOS_LOG_PATH" "./logs"
else
    echo "[AMOS] Running benchmark..."
    python3 test_gemm_nt.py --trials 1000 --simple_mode 1 | tee operators_shape_nt.log
fi
# Path: artifact/Figure12/amos-benchmark/benchmark_amos_gemm.sh
