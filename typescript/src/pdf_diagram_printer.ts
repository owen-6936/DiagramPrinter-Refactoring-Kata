import { DiagramMetadata, FlowchartDiagram } from "./documents";

export function PDFDiagramPrinter(
  diagram: FlowchartDiagram,
  targetFilename: string,
  info: DiagramMetadata
) {
  console.info(`Printing PDF to file ${targetFilename}`);
  return (function copyPDFFile() {
    return diagram!
      .flowchartAsPdf()
      .copyFile(info.fullFilename, targetFilename, true);
  })();
}
