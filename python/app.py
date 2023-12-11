#!/usr/bin/env python3
import pygame as pg
import sys
import random

pg.init()


SIZE = WIDTH, HEIGHT = 930, 800
WHITE = (255, 255, 255)
BALCK = (0, 0, 0)
RED   = (255, 0, 0)
FPS = 60
bar_w = 5
n = WIDTH // bar_w

def refill():
    screen.fill(WHITE)
    draw()
    pg.display.update()
    pg.time.delay(1000 // FPS)
    
    
def partition(array, low, high):
    piv = array[high]
    j = low - 1
    for i in range(low, high):
        if piv >= array[i]:
            j += 1
            (array[j], array[i]) = (array[i], array[j])

    refill()
    j += 1
    (array[j], array[high]) = (array[high], array[j])
    return j


def quicksort(array, low, high):
    if low < high:
        piv = partition(array, low, high)
        
        quicksort(array, low, piv - 1)
        refill()
        quicksort(array, piv + 1, high)

    
def generate_random_array():
    return [random.randint(10, HEIGHT) for _ in range(n)]

def draw():
    for i in range(len(array)):
        rect = pg.Rect(i * (bar_w + 1), HEIGHT - array[i], bar_w, array[i])
        pg.draw.rect(screen, RED, rect)
    
array = generate_random_array()

screen = pg.display.set_mode(SIZE)
pg.display.set_caption("Quick Sort")
clock = pg.time.Clock()

while True:
    clock.tick(FPS)
    screen.fill(WHITE)
    for event in pg.event.get():
        if event.type == pg.QUIT:
            pg.quit()
            sys.exit()
        
    quicksort(array, 0, len(array) - 1)
    pg.display.update() 