# :new_moon: Raytracer in C from scratch

## :cd: Installation
The project only work on Mac OS X.

It uses the MinilibX, a micro-library that provides an easy way to create a window and push an image on it.
```
make
```

## :monkey: Usage
```
./rtv1 xx.rtv1
```

## :movie_camera: Creation of a scene
To render your own scene into our raytracer, you have to create a .rtv1 file, the syntax is really easy to understand, it is a really simple implementation of a YAML format.

A simple example is sufficient to understand the syntax :
```
sphere:
  color: 255 67 82
  radius: 30
  origin: 100.4 45 678

# A comment
plane:
    ...
```

## :muscle: Authors
* [**Mathilde Yernaux**](https://github.com/myernaux)
* [**Octavio Orlando**](https://github.com/ocojeda)
* [**Basile Beldame**](https://github.com/bbeldame)
* [**Timothée Faure**](https://github.com/tfaure42)