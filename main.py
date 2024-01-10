#%%
from voiceCoilsClass import voiceCoils

if __name__ == "__main__":

    port = "COM3"
    VCdevice = voiceCoils()
    VCdevice.connect(port)
    
    #%%
    val1 = -1
    val2 = 0
    

    VCdevice.goto(val1,val2)

    #%%
    VCdevice.close()

# %%
