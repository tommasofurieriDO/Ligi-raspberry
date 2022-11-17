#%%
from voiceCoilsClass import voiceCoils

if __name__ == "__main__":

    port = "COM3"
    VCdevice = voiceCoils()
    VCdevice.connect(port)
    
    #%%
    val1 = -0.9
    val2 = -0.5

    VCdevice.goto(val1,val2)

    #%%
    VCdevice.close()
