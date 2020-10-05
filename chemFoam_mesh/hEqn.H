{
    volScalarField& h = thermo.he();

    forAll(h,celli)
    {
        if (constProp == "volume")
        {
            h[celli] = u0[celli] + p[celli]/rho[celli] + integratedHeat[celli];
        }
        
        else
        {
            h[celli] = h0[celli] + integratedHeat[celli];
        }
    }


    thermo.correct();


    Info<< "min/max(T) = "
        << min(T).value() << ", " << max(T).value() << endl;
}