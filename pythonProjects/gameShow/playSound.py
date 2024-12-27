import pygame.mixer
soundObj = pygame.mixer
soundObj.init()

def waitForFinish(channel):
    while(channel.get_busy()):
        pass

def playSoundFile(file):
    s = soundObj.Sound(file)
    waitForFinish(s.play())


