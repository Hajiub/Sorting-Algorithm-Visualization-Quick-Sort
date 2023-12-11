#!/usr/bin/env python3
import pygame as pg
import sys
import random

pg.init()

SIZE = WIDTH, HEIGHT = 930, 800
WHITE = (255, 255, 255)
RED = (255, 0, 0)
BAR_WIDTH = 10
FPS = 60
array = []

def draw_bars(array):
    for i in range(len(array)):
        rect = pg.Rect(i * (BAR_WIDTH + 1), HEIGHT - array[i], BAR_WIDTH, array[i])
        pg.draw.rect(screen, RED, rect)

def refill_screen(array):
    screen.fill(WHITE)
    draw_bars(array)
    pg.display.update()
    pg.time.delay(1000 // FPS)

def partition(array, low, high):
    pivot = array[high]
    i = low - 1
    for j in range(low, high):
        if array[j] <= pivot:
            i += 1
            array[i], array[j] = array[j], array[i]
    array[i + 1], array[high] = array[high], array[i + 1]
    return i + 1

def quicksort(array, low, high):
    if low < high:
        pivot_index = partition(array, low, high)
        quicksort(array, low, pivot_index - 1)
        refill_screen(array)
        quicksort(array, pivot_index + 1, high)

def generate_random_array():
    return [random.randint(10, HEIGHT) for _ in range(WIDTH // BAR_WIDTH)]

array = generate_random_array()
screen = pg.display.set_mode(SIZE)
pg.display.set_caption("Quick Sort")
clock = pg.time.Clock()

running = True
while running:
    screen.fill(WHITE)
    for event in pg.event.get():
        if event.type == pg.QUIT:
            running = False
        if event.type == pg.KEYDOWN:
            if event.key == pg.K_r:
                array = generate_random_array()
            elif event.key == pg.K_SPACE:
                quicksort(array, 0, len(array) - 1)
    
    
    draw_bars(array)
    pg.display.update()
    clock.tick(FPS)

pg.quit()
sys.exit()
