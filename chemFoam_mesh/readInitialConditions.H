    const word constProp(initialConditions.lookup("constantProperty"));
    if
    (
        (constProp != "pressure")
     && (constProp != "volume")
     && (constProp != "temperature")
    )
    {
        FatalError
            << "in initialConditions, unknown constantProperty type "
            << constProp << nl
            << "    Valid types are: pressure volume temperature."
            << exit(FatalError);
    }
/*
    const word fractionBasis(initialConditions.lookup("fractionBasis"));
    if ((fractionBasis != "mass") && (fractionBasis != "mole"))
    {
        FatalError << "in initialConditions, unknown fractionBasis type " << nl
            << "Valid types are: mass or mole."
            << fractionBasis << exit(FatalError);
    }

    const label nSpecie = Y.size();
*/
    const scalarList W(::W(thermo));
/*
    scalarList Y0(nSpecie, 0.0);
    scalarList X0(nSpecie, 0.0);

    dictionary fractions(initialConditions.subDict("fractions"));
    if (fractionBasis == "mole")
    {
        forAll(Y, i)
        {
            const word& name = Y[i].name();
            if (fractions.found(name))
            {
                X0[i] = fractions.lookup<scalar>(name);
            }
        }

        scalar mw = 0.0;
        const scalar mTot = sum(X0);
        forAll(Y, i)
        {
            X0[i] /= mTot;
            mw += W[i]*X0[i];
        }

        forAll(Y, i)
        {
            Y0[i] = X0[i]*W[i]/mw;
        }
    }
    else  // mass fraction
    {
        forAll(Y, i)
        {
            const word& name = Y[i].name();
            if (fractions.found(name))
            {
                Y0[i] = fractions.lookup<scalar>(name);
            }
        }

        scalar invW = 0.0;
        const scalar mTot = sum(Y0);
        forAll(Y, i)
        {
            Y0[i] /= mTot;
            invW += Y0[i]/W[i];
        }
        const scalar mw = 1.0/invW;

        forAll(Y, i)
        {
            X0[i] = Y0[i]*mw/W[i];
        }
    }
*/
    volScalarField h0
    (
        IOobject
        (
            "h0",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE,
            false
        ),
        mesh,
        dimensionedScalar("h0", dimEnergy/dimMass, 0.0)
    );
    const label nSpecie = Y.size();

   volScalarField rho0
    (
        IOobject
        (
            "rho0",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        mesh,
        0.0
        );
   volScalarField u0
    (
        IOobject
        (
            "u0",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        mesh,
        0.0
        );

    forAll(h0,celli)
    {
        scalarList Y0(nSpecie, 0.0);
        forAll(Y, i)
        {
            Y0[i] = Y[i][celli];
            //volScalarField& Yi = Y[i];
            //h0[celli] += Yi[celli]*specieData[i].Hs(p[celli], T[celli]);
        }
        h0[celli] = ::h0(thermo,Y0,p[celli],T[celli]);
    }



    //thermo.he() = dimensionedScalar(dimEnergy/dimMass, h0);
    //thermo.correct();

    rho = thermo.rho();
    forAll(Rspecific,celli)
    {
        u0[celli] = h0[celli] - p[celli]/rho[celli];
        scalar R0 = p[celli]/(rho[celli]*T[celli]);
        Rspecific[celli] = R0;
        rho0[celli] = rho[celli];
    }
    thermo.correct();
   volScalarField integratedHeat
    (
        IOobject
        (
            "integratedHeat",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        mesh,
        0.0
        ); 
