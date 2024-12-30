import pygame.mixer

def waitForFinish(channel):
    """Wait for the audio channel to finish playing."""
    while channel.get_busy():
        pass

def playSoundFile(file):
    """Play a sound file and wait for it to finish."""
    try:
        # Load the sound file
        sound = pygame.mixer.Sound(file)
        # Play the sound and wait for it to finish
        waitForFinish(sound.play())
    except pygame.error as e:
        print(f"Error playing sound file '{file}': {e}")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

# Initialize pygame mixer
try:
    pygame.mixer.init()
    print("Sound system initialized successfully.")
except pygame.error as e:
    print(f"Error initializing sound system: {e}")
except Exception as e:
    print(f"An unexpected error occurred during initialization: {e}")
