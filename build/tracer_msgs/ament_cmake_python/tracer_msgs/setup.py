from setuptools import find_packages
from setuptools import setup

setup(
    name='tracer_msgs',
    version='0.3.3',
    packages=find_packages(
        include=('tracer_msgs', 'tracer_msgs.*')),
)
