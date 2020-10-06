if (adjustTimeStep)
{
    //- Find the minimum dtChem across ranks and reduce
    reduce(dtChem, minOp<scalar>());

    //- Set the runtime to dtChem, if it is between minDeltaT and maxDeltaT
    runTime.setDeltaT(min(max(dtChem, minDeltaT), maxDeltaT));
    Info << "deltaT = " << runTime.deltaT().value() << endl;
}
