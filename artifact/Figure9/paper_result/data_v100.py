llama2_providers = ["BS1 SEQ1", "BS32 SEQ1", "BS1 SEQ4096"]
llama2_times_data = [
    ("PyTorch-Inductor", [1.488471031, 1.450066566, 37.87029266]),
    ("ONNXRuntime", [1.4079, 1.5685, 57.3798]),
    ("TensorRT", [1.16595, 1.25757, 50.5559]),
    ("Welder", [1.206272, 1.313792, 35.486721]),
    ("vLLM", [1.151266098, 1.255710125, 30.373981]),
    ("vLLM-W$_{INT4}$A$_{FP16}$", [0.634393692, 1.188759804, 126.0491967]),
    ("Bitter", [1.0305, 1.3976, 33.7857]),
    ("Bitter-W$_{INT4}$A$_{FP16}$", [0.3437, 1.233927747, 29.94758645]),
    ("Bitter-W$_{NF4}$A$_{FP16}$", [0.5152, 1.3209758, 32.03680507]),
    ("Bitter-W$_{FP8}$A$_{FP8}$", [0.584, 1.163299968, 29.25529448]),
    ("Bitter-W$_{MXFP8}$A$_{MXFP8}$", [0.8467, 1.40422857, 36.6284164]),
    ("Bitter-W$_{INT1}$A$_{INT8}$", [0.1571, 0.717229423, 24.44975112]),
]


bloom_providers = ["BS1 SEQ1", "BS32 SEQ1", "BS1 SEQ4096"]
bloom_times_data = [
    ("PyTorch-Inductor", [3.263437748, 3.431208134, 96.05407238]),
    ("ONNXRuntime", [3.2469, 3.9225, 166.2338]),
    ("TensorRT", [3.09532, 3.15014, 114.608]),
    ("Welder", [3.23072, 3.418464, 119.161346]),
    ("vLLM", [3.150303364, 3.419222832, 96.04342937]),
    ("vLLM-W$_{INT4}$A$_{FP16}$", [1.50655508, 3.269190788, 400.1646352]),
    ("Bitter", [2.845, 3.1374, 97.4431]),
    ("Bitter-W$_{INT4}$A$_{FP16}$", [0.83263518, 2.271361856, 90.92834427]),
    ("Bitter-W$_{NF4}$A$_{FP16}$", [1.306951993, 2.665507017, 106.2114859]),
    ("Bitter-W$_{FP8}$A$_{FP8}$", [1.514414341, 2.241219281, 91.7849889]),
    ("Bitter-W$_{MXFP8}$A$_{MXFP8}$", [1.983047948, 3.184281855, 105.1573525]),
    ("Bitter-W$_{INT1}$A$_{INT8}$", [0.324935987, 1.227464451, 67.368804]),
]

resnet_providers = ["BS1", "BS128"]
resnet_times_data = [
    ("PyTorch-Inductor", [3.428807259, 12.08203793]),
    ("ONNXRuntime", [3.1441, 42.8913]),
    ("TensorRT", [1.33123, 11.9807]),
    ("AMOS", [2.84198, 96.20838]),
    ("TensorIR", [1.597476, 17.47901487]),
    ("Welder", [1.851392, 16.895967]),
    ("Bitter", [1.1293, 7.9936]),
    ("Bitter_W$_{FP8}$A$_{FP8}$", [1.1293, 7.9936]),
    ("Bitter-W$_{MXFP8}$A$_{MXFP8}$", [2.090630394, 9.535129626]),
    ("Bitter_W$_{INT1}$A$_{INT4}$", [1.1293, 7.316121701]),
]

shufflenet_providers = ["BS1", "BS128"]
shufflenet_times_data = [
    ("PyTorch-Inductor", [4.203529358, 3.97033453]),
    ("ONNXRuntime", [2.0505, 7.4594]),
    ("TensorRT", [1.143, 5.12898]),
    ("AMOS", [0.69928, 21.73223]),
    ("TensorIR", [0.5235584, 5.187819268]),
    ("Welder", [0.369664, 4.110336]),
    ("Bitter", [0.3212, 3.3497]),
    ("Bitter_W$_{FP8}$A$_{FP8}$", [0.3212, 3.3531816]),
]

conformer_providers = ["BS1", "BS128"]
conformer_times_data = [
    ("PyTorch-Inductor", [7.941379547, 70.78004599]),
    ("ONNXRuntime", [5.8839, 220.7129]),
    ("TensorRT", [2.04296, 60.245]),
    ("AMOS", [0, 0]),
    ("TensorIR", [0, 0]),
    ("Welder", [1.953792, 84.503944]),
    ("Bitter", [2.06128, 60.2678]),
    ("Bitter-W$_{INT4}$A$_{INT8}$", [1.844756129, 56.28604248]),
    ("Bitter-W$_{INT4}$A$_{INT4}$", [1.707495592, 53.98872026]),
]

vit_providers = ["BS1", "BS128"]
vit_times_data = [
    ("PyTorch-Inductor", [3.427624702, 4.535059929]),
    ("ONNXRuntime", [2.605, 12.0053]),
    ("TensorRT", [0.667603, 3.07507]),
    ("AMOS", [0, 0]),
    ("TensorIR", [1.2807664, 6.145351825]),
    ("Welder", [1.190912, 5.554176]),
    ("Bitter", [1.210912, 4.2378]),
    ("Bitter-W$_{FP8}$A$_{FP8}$", [1.210912, 4.080552524]),
    ("Bitter-W$_{INT4}$A$_{INT4}$", [1.210912, 3.49672571]),
]