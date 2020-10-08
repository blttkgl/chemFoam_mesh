volScalarField Told
(
    IOobject
    (
        "Told",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("Told", dimTemperature, 0.0)
);

volScalarField Tcurr
(
    IOobject
    (
        "Tcurr",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("Tcurr", dimTemperature, 0.0)
);

volScalarField maxGradT
(
    IOobject
    (
        "maxGradT",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("maxGradT", dimTemperature, -VGREAT)
);

volScalarField gradTcurr
(
    IOobject
    (
        "gradTcurr",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("gradTcurr", dimTemperature, VGREAT)
);


volScalarField initialT
(
    IOobject
    (
        "initialT",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    thermo.T()
);
scalar timestep;
scalar startTime = runTime.value();

volScalarField IDT
(
    IOobject
    (
        "IDT",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("IDT", dimTime, 0.0)
);

