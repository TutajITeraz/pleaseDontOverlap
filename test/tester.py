import dearpygui.dearpygui as dpg
import dearpygui.demo as demo
from math import sin
import numpy as np

x1 = np.random.random(100)
x2 = np.random.random(100)
label = np.random.randint(0, 4, 100)

#importing our c++ implementation of the function
from ctypes import *
libc = CDLL("libc.so.6") 
LabelFilter = cdll.LoadLibrary("build/src/libLabelFilter.so") 

#my_label_filter = LabelFilter.CreateInstanceOfLabelFilter()

class POINT(Structure):
    _fields_ = [("x", c_double),
                ("y", c_double)]

class SIZE(Structure):
    _fields_ = [("w", c_double),
                ("h", c_double)]

class COORDINATES(Structure):
    _fields_ = [("lon", c_double),
                ("lat", c_double)]

class LABEL(Structure):
    _fields_ = [("name", c_char_p),
                ("position", COORDINATES),
                ("pivot", POINT),
                ("size", SIZE),
                ("priority", c_double),
                ]

point = POINT(9,10)

label = LABEL("test", COORDINATES(1,2), POINT(3,4), SIZE(5,6), 1.5)

#CallLabelFilterSetList(my_label_filter)

print(LabelFilter)

def generate_labels():
    print("Labels generated")


dpg.create_context()
dpg.create_viewport(title="Please don't overlap - Tester", width=800, height=600)

#demo.show_demo()

# creating data
sindatax = []
sindatay = []
for i in range(0, 500):
    sindatax.append(i / 1000)
    sindatay.append(0.5 + 0.5 * sin(50 * i / 1000))

with dpg.window(label="Tutorial"):
    # create plot
    with dpg.plot(label="Line Series", height=500, width=700):
        dpg.add_plot_legend()
        dpg.add_plot_axis(dpg.mvXAxis, label="x")
        _axis_id = dpg.add_plot_axis(dpg.mvYAxis, label="y")

        for i in range(100):
            dpg.add_scatter_series(
                x1[i], x2[i], label=f"{label[i]}", parent=_axis_id, use_internal_label=False
            )


with dpg.window(label="Controls"):
    dpg.add_text("Generate sample labels")
    dpg.add_button(label="Generate sample labels", callback=generate_labels)
    dpg.add_input_text(label="label_test")
    dpg.add_slider_float(label="how_many")



dpg.setup_dearpygui()



dpg.show_viewport()
dpg.start_dearpygui()
dpg.destroy_context()

